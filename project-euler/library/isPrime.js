// check Prime num

function isPrime(num) {
	let result = true

	for (var i = 2; i <= Math.sqrt(num); i++) {
		
		if (num % i === 0) {

			result = false

		}

	}

	return result
}