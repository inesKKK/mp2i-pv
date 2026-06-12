import math

def convolution(M, F):
    C = [ [0]*len(M[i]) for i in range(len(M)) ]
    for k in range(len(C)):
        for l in range(len(C[k])):
            for i in range(-(len(F)//2), len(F)//2+1):
                for j in range(-(len(F[i])//2), len(F)//2+1):
                    if k+i >= 0 and k+i < len(M) and l+j >= 0 and l+j < len(M[i]):
                        C[k][l] += M[k+i][l+j]*F[len(F)//2+i][len(F[i])//2+j]
    return C

Laplacien = [
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, 24, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1]
]

Gx = [
    [1, 0, -1],
    [2, 0, -2],
    [1, 0, -1]
]

Gy = [
    [1, 2, 1],
    [0, 0, 0],
    [-1, -2, -1]
]

def gradient(M):
    return (convolution(M, Gx), convolution(M, Gy))


def norme(u):
    return math.sqrt(u[0]*u[0] + u[1]*u[1])

def fZ(laplM, Q):
    return 0 if laplM[Q[0]][Q[1]] < 0.00001 else 1

def grad_max(gradMx, gradMy):
    m = 0
    for i in range(len(gradMx)):
        for j in range(len(gradMx[i])):
            m2 = norme((gradMx[i][j],gradMy[i][j]))
            if m2 > m:
                m = m2
    return m

def fG(gradMx, gradMy, gradMax, Q):
    nQ = norme((gradMx[Q[0]][Q[1]], gradMy[Q[0]][Q[1]]))
    return 1 - nQ / gradMax

def produit_scalaire(u, v):
    return u[0]*v[0] + u[1]*v[1]

def dX(gradMx, gradMy, P, Q, X):
    epsilon = 0.000000001
    gradX = (gradMx[X[0]][X[1]], gradMy[X[0]][X[1]])
    norme_gradX = norme(gradX)
    if norme_gradX < epsilon:
        return 0
    DX = (gradX[1]/norme_gradX, -gradX[0]/norme_gradX)
    gradP = (gradMx[P[0]][P[1]], gradMy[P[0]][P[1]])
    DP = (gradP[1], -gradP[0])
    normePQ = norme((Q[0]-P[0], Q[1]-P[1]))
    LPQ = ((Q[0]-P[0])/normePQ, (Q[1]-P[1])/normePQ) if produit_scalaire(DP, [Q[0]-P[0], Q[1]-P[1]])>=0\
        else ((P[0]-Q[0])/normePQ, (P[1]-Q[1])/normePQ)
    return produit_scalaire(DX, LPQ)

def fD(gradMx, gradMy, P, Q):
    return 2/(3*math.pi)*(math.acos(dX(gradMx, gradMy, P, Q, P)) + math.pi - math.acos(dX(gradMx, gradMy, P, Q, Q)))



def poids(laplM, gradMx, gradMy, gradMax, P, Q):
    """donne le poids de l'arête entre les point P et Q fournis par leurs coordonnées"""
    fz = fZ(self.laplM, Q)
    fg = fG(self.gradMx, self.gradMy, self.gradMax, Q)
    fd = fD(self.gradMx, self.gradMy, P, Q)
    return 0.43 * fz + 0.43 * fg + 0.14 * fd

