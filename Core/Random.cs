
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public static class Random {

        private static System.Random rand = new System.Random();

        public static float Range(float _minInclusive, float _maxInclusive) {
            float temp = rand.NextSingle();
            temp.Map(0, 1, _minInclusive, _maxInclusive);
            return temp;
        }

    }
    
}