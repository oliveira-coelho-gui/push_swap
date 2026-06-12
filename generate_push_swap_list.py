import random

def generate_push_swap_list(dis: float, n: int):
    # 1. Calcular o número exato de inversões necessárias
    total_pairs = (n * (n - 1)) // 2
    target_inversions = int(round(dis * total_pairs))
    
    # 2. Definir a capacidade máxima de inversões para cada índice
    # O elemento no índice i pode ter no máximo (n - 1 - i) inversões
    capacities = [n - 1 - i for i in range(n)]
    
    # 3. Distribuir as inversões de forma aleatória para evitar padrões artificiais
    L = [0] * n
    indices = list(range(n))
    random.shuffle(indices) 
    
    rem_cap = total_pairs
    rem_inv = target_inversions
    
    for i in indices:
        cap_i = capacities[i]
        rem_cap -= cap_i # Capacidade que vai sobrar nos outros índices
        
        # O mínimo necessário para não faltar capacidade no final
        min_val = max(0, rem_inv - rem_cap)
        # O máximo que cabe nesse índice sem passar do alvo
        max_val = min(rem_inv, cap_i)
        
        # Sorteia um valor válido e seguro
        val = random.randint(min_val, max_val)
        L[i] = val
        rem_inv -= val
        
    # 4. Construir a lista final a partir do código de Lehmer
    elements = list(range(1, n + 1))
    result = []
    for i in range(n):
        # L[i] indica exatamente o índice do elemento que devemos extrair
        idx = L[i]
        result.append(elements.pop(idx))
        
    # Imprime a lista separada por espaços, pronta para o push_swap
    print(" ".join(map(str, result)))

# Exemplo: Gerando uma lista de 20 números com 50% de desordem
generate_push_swap_list(0.79, 200)
