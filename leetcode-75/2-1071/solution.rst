HOW IT SOLVED
-------------

1. get the length of each string(src -> shorter one, dest -> longer one)
#. get the divisor of length src(bigger to smaller)

   - check div of srclen is div of dest also (NO? go to 2)
   - check divcount of src make pattern in src (NO? go to 2)
   - check divcount of src make pattern in dest (NO? go to 2)
      - YES: that's the longest part of parttern from src to dest string.

