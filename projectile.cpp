#include "projectile.hpp"
#include <cmath>

const double m = 1;
const double g = 9.8066;
const double dt = 0.001;
const double k = 0.5;
const double q = 1;
const double w = 2;
const double e0 = 1;

auto force(TState s) { 
	return VecR3<double>{(e0/sqrt(2)*cos(k*s.position.z - w*s.t)), (e0/sqrt(2)*sin(k*s.position.z - w*s.t)), 0}; 
}

auto verlet_step(TState s, VecR3<double> accel) {
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt) + (0.5*accel*pow(dt, 2));
  next.velocity = s.velocity + (0.5*dt*(accel + (force(next)/m)));
  return next;
}

void n_steps(unsigned n, TState state0) {
  print_tstate(state0);
  if (n == 0)
    return;
  else {
    auto state = state0;
    for (unsigned k = 0; k < n; ++k) {
      state = verlet_step(state, force(state) / m);
      print_tstate(state);
    }
  }
}

int main() {
  n_steps(10000, TState{0., {-e0/(pow(w,2)*sqrt(2)), 0, 0}, {0, e0/(w*sqrt(2)), -0.25}});
  return 0;
}
