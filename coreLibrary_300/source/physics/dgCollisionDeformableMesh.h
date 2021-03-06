/* Copyright (c) <2003-2016> <Julio Jerez, Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 
* 3. This notice may not be removed or altered from any source distribution.
*/


#ifndef __DGCOLLISION_DEFORMABLE_MESH_H__
#define __DGCOLLISION_DEFORMABLE_MESH_H__


#include "dgCollision.h"
#include "dgCollisionConvex.h"

class dgCollisionDeformableMesh: public dgCollisionConvex
{
	public:
	dgCollisionDeformableMesh (const dgCollisionDeformableMesh& source);
	dgCollisionDeformableMesh (dgWorld* const world, dgMeshEffect* const mesh, dgCollisionID collsionID);
	dgCollisionDeformableMesh (dgWorld* const world, dgDeserialize deserialization, void* const userData, dgInt32 revisionNumber);
	virtual ~dgCollisionDeformableMesh(void);

	dgInt32 GetLinksCount() const;
	dgInt32 GetParticleCount() const;

	const dgInt16* GetLinks() const;
	const dgVector* GetVelocity() const;
	const dgVector* GetPositions() const;
	const dgInt32* GetParticleToVertexMap() const;
	virtual void ConstraintParticle(dgInt32 particleIndex, const dgVector& posit, const dgBody* const body);

	void DisableInactiveLinks ();

	protected:
	virtual dgInt32 CalculateSignature() const;
	virtual void SetCollisionBBox(const dgVector& p0, const dgVector& p1);
	virtual void Serialize(dgSerialize callback, void* const userData) const;
	virtual void CollideMasses(dgDynamicBody* const myBody, dgBody* const otherBody);

	class dgSoftLink;
	class dgSpringMassSolver;
	
	virtual void CalcAABB(const dgMatrix& matrix, dgVector& p0, dgVector& p1) const;
	virtual void IntegrateForces(dgDynamicBody* const body, dgFloat32 timestep);
	virtual dgMatrix CalculateInertiaAndCenterOfMass(const dgMatrix& m_alignMatrix, const dgVector& localScale, const dgMatrix& matrix) const;

//	void CalculatePartialDerivatives (dgMatrix* const dfdx) const;
	void CalculateGlobalConstants (dgFloat32 timestep, dgFloat32* const spring_A01, dgFloat32* const spring_B01, dgVector* const linkDisplacement) const;
	void CalculateRightHandSide (dgVector* const rhs, const dgDynamicBody* const body, const dgFloat32* const spring_A01, const dgFloat32* const spring_B01, const dgVector* const linkDisplacement) const;

	dgVector* m_posit;
	dgVector* m_veloc;
	dgFloat32* m_lambda;
	dgInt32* m_indexMap;
	dgSoftLink* m_linkList;
	dgFloat32* m_restlength;
	dgVector* m_externalforce;
	dgFloat32* m_unitMassScaler;

	dgInt32 m_linksCount;
	dgInt32 m_massesCount;
	dgInt32 m_vertexCount;

	static dgVector m_smallestLenght2;

	friend class dgBroadPhase;
	friend class dgDynamicBody;
	friend class dgWorldDynamicUpdate;
};


#endif 

