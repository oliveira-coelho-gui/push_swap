#!/bin/bash

# ==========================================
# Cores para o output
# ==========================================
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

# ==========================================
# Validação do ambiente
# ==========================================
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Erro: O executável ./push_swap não foi encontrado.${NC}"
    echo "Compile o projeto antes de rodar o tester."
    exit 1
fi

# Se você tiver o checker, mude para true e ajuste o nome do binário
USE_CHECKER=true
CHECKER_BIN="./checker_linux"

# ==========================================
# Criação do gerador Python em tempo de execução
# ==========================================
cat << 'EOF' > .gen_list.py
import sys, random

def generate_push_swap_list(dis, n):
    total_pairs = (n * (n - 1)) // 2
    target_inversions = int(round(dis * total_pairs))
    capacities = [n - 1 - i for i in range(n)]
    L = [0] * n
    indices = list(range(n))
    random.shuffle(indices)
    
    rem_cap = total_pairs
    rem_inv = target_inversions
    
    for i in indices:
        cap_i = capacities[i]
        rem_cap -= cap_i
        min_val = max(0, rem_inv - rem_cap)
        max_val = min(rem_inv, cap_i)
        val = random.randint(min_val, max_val)
        L[i] = val
        rem_inv -= val
        
    elements = list(range(1, n + 1))
    result = []
    for i in range(n):
        result.append(elements.pop(L[i]))
    print(" ".join(map(str, result)))

disorder = float(sys.argv[1])
size = int(sys.argv[2])
generate_push_swap_list(disorder, size)
EOF

# ==========================================
# Configuração dos Parâmetros de Teste
# ==========================================
# Tamanhos: 5 (básico), 100 e 500 (avaliados na defesa)
SIZES=(10 100 200 400 500 800)

# Graus de desordem (0.0 = ordenado, 1.0 = inversamente ordenado)
DISORDERS=(0.0 0.05 0.1 0.15 0.2)

echo -e "${BLUE}Iniciando Bateria de Testes do Push_swap${NC}"
echo "=========================================="

for size in "${SIZES[@]}"; do
    echo -e "\n${YELLOW}>>> Testando Tamanho: $size elementos <<<${NC}"
    printf "%-12s | %-12s | %-19s | %-10s\n" "Desordem" "Operações" "Status" "Checker"
    printf "%s\n" "---------------------------------------------------------"

    for dis in "${DISORDERS[@]}"; do
        # 1. Gera a lista
        ARG=$(python3 .gen_list.py "$dis" "$size")
        
        # 2. Executa o push_swap (garante a contagem limpa de quebras de linha)
        OPS_OUTPUT=$(./push_swap --adaptive $ARG 2>/dev/null)
        
        if [ -z "$OPS_OUTPUT" ]; then
            OPS=0
        else
            OPS=$(echo "$OPS_OUTPUT" | wc -l)
        fi

        # 3. Avalia os limites baseados no tamanho
        STATUS="${GREEN}OK${NC}"
        if [ "$size" -eq 100 ]; then
            if [ "$OPS" -ge 2000 ]; then STATUS="${RED}FAIL (>2000)${NC}"
            elif [ "$OPS" -ge 1500 ]; then STATUS="${YELLOW}PASS (<2000)${NC}"
            elif [ "$OPS" -ge 700 ]; then STATUS="${BLUE}GOOD (<1500)${NC}"
            else STATUS="${GREEN}EXCELLENT (<700)${NC}"; fi
        elif [ "$size" -eq 500 ]; then
            if [ "$OPS" -ge 12000 ]; then STATUS="${RED}FAIL (>12000)${NC}"
            elif [ "$OPS" -ge 8000 ]; then STATUS="${YELLOW}PASS (<12000)${NC}"
            elif [ "$OPS" -ge 5500 ]; then STATUS="${BLUE}GOOD (<8000)${NC}"
            else STATUS="${GREEN}EXCELLENT (<5500)${NC}"; fi
        fi

        # 4. Verificação opcional do Checker
        CHECK_RES="N/A"
        if [ "$USE_CHECKER" = true ] && [ "$OPS" -gt 0 ]; then
            CHECK_RES=$(echo "$OPS_OUTPUT" | $CHECKER_BIN $ARG 2>/dev/null)
            if [ "$CHECK_RES" = "OK" ]; then
                CHECK_RES="${GREEN}OK${NC}"
            else
                CHECK_RES="${RED}KO${NC}"
            fi
        fi

        # 5. Imprime a linha de resultado
		printf "%-12s | %-10s | %-30b | %-31b\n" "$dis" "$OPS" "$STATUS" "$CHECK_RES"
    done
done

echo -e "\n${BLUE}Limpando arquivos temporários...${NC}"
rm -f .gen_list.py
echo "Testes concluídos."
