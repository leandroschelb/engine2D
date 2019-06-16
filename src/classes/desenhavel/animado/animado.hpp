#ifndef ANIMADO_HPP
#define ANIMADO_HPP

#include <string>
#include <vector>
#include "../../../include/Item.hpp"
#include "../desenhavel.hpp"

/**
 * Classe para entidades desenháveis vivas.
 */
class Animado : public Desenhavel
{
private:
  std::string nome;
  int vida;
  int maxVida;
  int variacaoMaxVida = 0; // se estiver com buf/debuf ou modificado por equipamento
  int defesa;
  int forca;
  int variacaoDefesa = 0; // se estiver com buf/debuf ou modificado por equipamento
  int variacaoForca = 0; // se estiver com buf/debuf ou modificado por equipamento
  float multiplicadorCritico;
  int chanceCritico;
  int chanceAcerto;
  std::vector<Item*> inventario;

  /**
   * Corrige a vida do jogador ao modificar propriedades de vida
   */
  void corrigirVida(void);
public:
	/**
	 * Construtor da classe Animado.
	 * @param nome nome da entidade (exemplo "Jogador", "Monstro")
	 * @param vida vida inicial da entidade
	 * @param maxVida valor máximo de vida da entidade
	 * @param defesa valor inicial de defesa da entidade
	 * @param forca valor inicial de força da entidade
	 * @param x coordenada x inicial da entidade
	 * @param y coordenada y inicial da entidade
	 * @param altura altura da entidade
	 * @param largura largura da entidade
	 * @param colisivo indica se é uma entidade que colide com outros objetos
	 * @param multiplicadorCritico é o valor ao qual o dano é multiplicado quando o ataque é crítico
	 * @param chanceCritico valor em porcentagem (0-100) da chance de crítico
	 * @param chanceAcerto valor em porcentagem (0-100) da chance de acerto de ataque
	 * @param red composição vermelha da cor do objeto (0-255)
	 * @param green composição verde da cor do objeto (0-255)
	 * @param blue composição azul da cor do objeto (0-255)
	 */
  Animado (std::string nome, int vida, int maxVida, int defesa, int forca, int x, int y, int altura, int largura, bool colisivo, float multiplicadorCritico, int chanceCritico, int chanceAcerto, int red, int green, int blue);

  /**
   * Getter para vida da entidade.
   * @return vida
   */
  int getVida(void);

  /**
   * Varia a vida da entidade de acordo com parâmetro e corrige para que não ultrapasse os limites (0, maxVida + variacaoMaxVida)
   * @param variacao valor a ser acrescido na vida da entidade.
   */
  void variarVida(int variacao);

  /**
   * Variação do máximo de vida.
   * @return variação max vida.
   */
  int getVariacaoMaxVida(void);

  /**
   * Configura a variação do máximo de vida, corrige a vida de acordo com novo valor.
   * @param variacao novo valor de variação do máximo de vida.
   */
  void setVariacaoMaxVida(int variacao);

  /**
   * Getter para máximo de vida, sem variação.
   * @return máximo de vida.
   */
  int getMaxVida(void);

  /**
   * Configura o valor máximo de vida da entidade e corrige a vida do personagem para que fique dentro dos limites.
   * @param maxVida novo valor de máximo de vida.
   */
  void setMaxVida(int maxVida);

  /**
   * Getter de defesa da entidade.
   * @return defesa.
   */
  int getDefesa(void);

  /**
   * Configura a defesa da entidade.
   * @param defesa novo valor de defesa.
   */
  void setDefesa(int defesa);

  /**
   * Getter de força da entidade.
   * @return força.
   */
  int getForca(void);

  /**
   * Configura força da entidade.
   * @param forca novo valor de força da entidade.
   */
  void setForca(int forca);

  /**
   * Getter de variação da defesa (valor de buf/debuf da defesa)
   * @return variação da defesa.
   */
  int getVariacaoDefesa(void);

  /**
   * Configura variação da defesa.
   * @param variacaoDefesa novo valor de variação da defesa.
   */
  void setVariacaoDefesa(int variacaoDefesa);

  /**
   * Getter de variação da força (valor de buf/debuf)
   * @return variação da força.
   */
  int getVariacaoForca(void);

  /**
   * Configura variação da força.
   * @param variacaoForca novo valor de variação de força.
   */
  void setVariacaoForca(int variacaoForca);

  /**
   * Máximo da vida da entidade acrescido da variação do máximo de vida da entidade.
   * @return maxVida + variacaoMaxVida.
   */
  int getTotalMaxVida (void);

  /**
   * Valor de força da entidade acrescido da variação de força.
   * @return força + variacaoForça ou 0 se a soma anterior for negativa.
   */
  int getTotalForca (void);

  /**
   * Valor de defesa acrescido da variação de defesa.
   * @return defesa + variacaoDefesa ou 0 se a soma anterior for negativa.
   */
  int getTotalDefesa (void);

  /**
   * Getter de inventário da entidade.
   * @return inventario.
   */
  // TODO:o que fazer com isso??? std::vector<Item*> getInventario(void);

  /**
   * Ataca uma entidade.
   * @param entidade entidade a receber o ataque.
   * @param critico ponteiro para booleano para indicar se o ataque foi crítico
   * @param erro ponteiro para booleano para indicar se o ataque foi errado.
   * @return dano (variação negativa de vida) causado a entidade.
   */
  int ataca (Animado& entidade, bool* critico, bool* erro);

  /**
   * Cura a entidade adicionando 4 em sua vida, respeitando os limites.
   */
  void cura (void);

  /**
   * Getter de multiplicador de ataque crítico do personagem.
   * @return multiplicador crítico.
   */
  float getMultiplicadorCritico (void);

  /**
   * Chance de ataque crítico da entidade, valor entre 0 e 100.
   * @return chance de ataque crítico.
   */
  int getChanceCritico (void);

  /**
   * Chance de acerto de ataque da entidade, valor entre 0 e 100.
   * @return chance de acerto de ataque.
   */
  int getChanceAcerto (void);

  /**
   * Verifica se a entidade está colidindo (está ao lado) com outra passada por parâmetro.
   * @param entidade entidade com a qual verifica-se colisão.
   * @return se há de fato colisão ou não.
   */
  bool colisaoComEntidade (Animado& entidade);
};

#endif
