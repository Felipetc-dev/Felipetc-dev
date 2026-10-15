#include <stdio.h>
#include <string.h>

void gerar_fibonacci(int n, int fib[]) {
    if (n > 0) fib[0] = 1;
    if (n > 1) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    char palavra[16];
    int shift;
    
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    
    printf("Digite a palavra secreta : ");
    scanf("%15s", palavra);
    
    printf("Digite o valor do SHIFT : ");
    scanf("%d", &shift);
    
    int tamanho = strlen(palavra);
    int fib[15];
    
    gerar_fibonacci(tamanho, fib);
    
    char palavra_criptografada[16];
    
    for (int i = 0; i < tamanho; i++) {
        char c = palavra[i];
        
        if (c >= 'a' && c <= 'z') {
            int posicao_atual = c - 'a';
            int deslocamento_total = shift + fib[i];
            int nova_posicao = (posicao_atual + deslocamento_total) % 26;
            palavra_criptografada[i] = alfabeto[nova_posicao];
        } else {
            palavra_criptografada[i] = c;
        }
    }
    palavra_criptografada[tamanho] = '\0';
    
    printf("\n--- RESULTADO DA CRIPTOGRAFIA ---\n");
    printf("Palavra original: %s\n", palavra);
    printf("Palavra criptografada: %s\n", palavra_criptografada);
    
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: Fibonacci | Letras: %d\n", 
                palavra_criptografada, shift, tamanho);
        fclose(arquivo);
        printf("\n[Sucesso] Ficheiro 'resultado_criptografia.txt' gerado!\n");
    } else {
        printf("\n[Erro] Nao foi possivel criar o ficheiro.\n");
    }
    
    return 0;
}