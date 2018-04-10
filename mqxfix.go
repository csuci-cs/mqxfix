package mqxtransform

import "math"

type Transformation struct {
	SensorNameGasName   string
	MinX, MaxX, C, B, A float64
}

var (
	MQ5_CO      = Transformation{"MQ5_CO", 2.28, 3.85, 10, -23.5, 17.7}
	MQ5_Alcholo = Transformation{"MQ5_Alcholo", 1.44, 3.46, 4.81, -4.5, 0}
	MQ5_H2      = Transformation{"MQ5_H2", 0.657, 1.75, 3.07, -3.83, 0}
	MQ5_CH4     = Transformation{"MQ5_CH4", 0.204, 0.949, 2.25, -2.55, 0}
	MQ5_LPG     = Transformation{"MQ5_LPG", 0.15, 0.705, 1.9, -2.48, 0}
	MQ9_CH4     = Transformation{"MQ9_CH4", 0.681, 3.06, 3.59, -2.59, 0}
	MQ9_LPG     = Transformation{"MQ9_LPG", 0.321, 2.05, 2.97, -2.11, 0}
	MQ9_CO      = Transformation{"MQ9_CO", 0.783, 1.6, 2.74, -2.22, 0}
	MQ131_NOx   = Transformation{"MQ131_NOx", 2.05, 7.87, 2.7, -2.26, 0}
)

func (t Transformation) Reading(rs, r0 float64) (float64, bool) {
	x := rs / r0

	logx := math.Log10(x)
	fixedReading := t.A*math.Pow(logx, 2) + t.B*logx + t.C

	return fixedReading, x > t.MinX && x < t.MaxX
}
