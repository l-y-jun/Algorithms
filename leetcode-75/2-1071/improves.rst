HOW TO IMPROVE
--------------

- divisor calculation is linear.

   - SOLUTION

      Make dividend to be smaller when divded by divisor(factorization)

   - VARIABLES

      - v: value
      - d: divisor (default, 1)
      - n: division value

   - HOWTO

      1. factorize 

         1. divide value, ``v`` by divisor ``d``.
         #. get the division value ``n``.
         #. push ``n``\, ``d`` to divisors list.
         #. set value of ``v``\ to ``n``.
      
      #. make divisors by factors
   
         1. minimum divisors are in a list ``divisors``.
         #. multiplication by factors in a set
         #. each result of multiplying also can be factorize but itself is divosor of value ``v``.

