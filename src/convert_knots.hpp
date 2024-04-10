double knots_to_miles_per_minute(int knots) {
	double value = ((double)knots*6076)/(5280*60);
	return value;
}
