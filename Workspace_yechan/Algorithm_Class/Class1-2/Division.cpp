// Division. (x == yq + r, where y!=0, y < y)

int divide(x,y) {
	if x=0
		return (q,r) = (0,0)
	(q, r) =divide(x/2, y)
	q=2*q, r=2*r
	if x is odd then
		r = r+1 
	else x>=y
		r = r - y, q = q + 1
	return (q,r);
}