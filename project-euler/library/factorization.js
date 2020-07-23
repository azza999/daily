// Factorization

function factorization (num) {
	
	let arr = [], i

	for (i = 2; i != num; i++) {
		
		if(num%i==0){

			arr.push(i)
			num /= i--;

		}

	}

	arr.push(i)

	return arr
}