#ifndef LIEN_H
#define LIEN_H

#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "entite.h"
#include <QColor>
#include "types.h"

/*Mes constantes*/
#define LEAKRELATION "Leak Relation"
#define ENTITY "Entity"
#define CIF "Cif"
#define RELATION "Relation"
#define DF "Df"
#define LEG "Leg"
//brief declarations
class Entite;
/**
 * @brief The Lien class
 * a link is betwwen to objects
 * it contains a line a role text cardinality ...
 */
class Lien : public QGraphicsItemGroup
{
public:
    enum { Type = LIEN};
    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return Type;
    }
    /**
     * @brief line
     * the line
     */
    QGraphicsLineItem * line;
    /**
     * @brief lignePointillee
     * nécessaire en cas de pseudo-entité (association prise comme entité)
     */
    QGraphicsLineItem * lignePointillee;
    /**
     * @brief t1
     *first object table1
     */
    Entite* t1;
    /**
     * @brief t2
     *second object table2
     */
    Entite* t2;
    /**
     * @brief cardinalite1
     * example:0,1 or 1,1 or 0,n
     */
    QGraphicsSimpleTextItem * cardinalite1;
    /**
     * @brief cardinalite2
     * example:0,1 or 1,1 or 0,n
     */
    QGraphicsSimpleTextItem * cardinalite2;
    //a utiliser quand il y a plusieurs liens entre deux même objets
    /**
     * @brief role
     * if there are several links between two same objects
     */
    QGraphicsSimpleTextItem* role;
    /**
     * @brief texteDuRole
     *  example: chief
     */
    QString texteDuRole;//idem ci-dessus
    ~Lien();
    /**
     * @brief Lien
     * @param qg1
     * @param qg2
     * @param parent
     * @param typ
     * @param relationName nom de l'association
     * @param pRole
     *this is constructor
     */
    Lien(Entite* qg1,Entite* qg2,QGraphicsItem* parent, QString typ="Natural",QString relationName="",QString pRole="");//constructeur
    //Cif,patte,...
    /**
     * @brief typeDeJointure
     * cif --1,1--CIF--0,n--> df --0,1--DF--0,n-->or leg -----------
     */
    QString typeDeJointure;
    //pour les cifs et dfs et entités faibles le rond central
    /**
     * @brief leRond
     *Pour les cifs et dfs et entités faibles le rond central
     */
    QGraphicsEllipseItem* leRond;
    /**
     * @brief leTexteDuRond
     * text writen into central disk
     */
    QGraphicsTextItem* leTexteDuRond;
    /**
     * @brief laFleche
     * pour les cifs et df la flêche
     */
    QGraphicsPolygonItem* laFleche;
    //menu contextuel du lien
    /**
     * @brief contextMenuEvent
     * @param event
     * show context Menu
     */
    void contextMenuEvent(QGraphicsSceneMouseEvent *event);//menu contextuel du lien
    /**
     * @brief estRelieA
     * @param autreLien
     * @return true if there is another link with same source or same destination
     */
    bool estRelieA(Lien* autreLien);
    /**
     * @brief calculeCoordonnes
     * calcule les coordonnées et les met à jour
     */
    void calculeCoordonnees();
    void ajouteElementsAuGroupe();
    bool reflexif;
};
#endif // LIEN_H