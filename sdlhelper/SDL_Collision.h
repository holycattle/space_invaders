#include "SDL_Vector.h"

//an implementation of AABB based from the code of Miguel Gomez of Gamasutra
class CollisionBox {
	public:
		SDL_SDL_Vector pos;
		SDL_SDL_Vector ext;
		CollisionBox(const SDL_Vector& p, const SDL_Vector& e):
			pos(p), ext(e) {}

		//returns true if this is overlapping b
		const bool isOverlapping( const CollisionBox& b ) const {
			const SDL_Vector T = b.pos - pos; //SDL_Vector from A to B

			return fabs(T.x) <= (E.x + b.E.x) &&
					fabs(T.y) <= (E.y + b.E.y) &&
					fabs(T.z) <= (E.z + b.E.z);
		}

		const Scalar min( long i ) const {
			return ((CollisionBox*)this)->pos[i] - ((CollisionBox*)this)->ext[i];
		}

		const Scalar max( long i ) const {
			return ((CollisionBox*)this)->P[i] + ((CollisionBox*)this)->E[i];
		}
};

const bool sweep
	(
		const SDL_Vector& extA,	//extents of AABB A
		const SDL_Vector& prevPosA,	//its previous position
		const SDL_Vector& currPosA,	//its current position
		const SDL_Vector& extB,	//extents of AABB B
		const SDL_Vector& prevPosB,	//its previous position
		const SDL_Vector& currPosB,	//its current position
		Scalar& u0,	//normalized time of first collision
		Scalar& u1	//normalized time of second collision
	)

{
	const CollisionBox prevStateA(prevPosA, extA);
	const CollisionBox prevStateB(prevPosB, extB);

	const SDL_Vector dA = currPosA - prevPosA;
	const SDL_Vector dB = currPosB - prevPosB;

	SDL_Vector relVelocity = dB - dA;

	SDL_Vector initialOverlap(0, 0, 0);
	SDL_Vector terminalOverlap(1, 1, 1);
}
