#ifndef ARAPDEFORMER_H
#define ARAPDEFORMER_H

#include "AbstractDeformer.h"
#include <Eigen/Dense>

class ARAPDeformer : public AbstractDeformer
{
protected:
    //The matrix D follows the definition on equation 5.
    Eigen::MatrixXd G;
    QVector<CDT::Vertex_handle> indexToVertex;
    QMap<CDT::Vertex_handle, int> vertexToIndex;
    int freeVertexCount;
    void buildVertexMap();
    void getLocalCoordinate(const QPointF &v0, const QPointF &v1, const QPointF &v2, float &x, float &y);
    void addStep1ErrorForTriangleEdge(const QPointF &v0, const QPointF &v1, const QPointF &v2,
                                      const int v0Index, const int v1Index, const int v2Index);
    void addStep1ErrorForTriangle(const QPointF &v0, const QPointF &v1, const QPointF &v2,
                                  const int v0Index, const int v1Index, const int v2Index);
    void step2FitTriangle(Eigen::MatrixXd& matrix, const QPointF &sV0, const QPointF &sV1, const QPointF &sV2,
                          const QPointF &tV0, const QPointF &tV1, const QPointF &tV2);
public:
    ARAPDeformer(CDT& triangleMesh);
    void prepare();
};

#endif // ARAPDEFORMER_H
