#include <stdio.h>
#include <string.h>
#define SUBJECT_COUNT 20

float personScore2score (char subScore[3])
{
	if (strncmp(subScore, "A+", 2) == 0) return 4.5;
	if (strncmp(subScore, "A0", 2) == 0) return 4.0;
	if (strncmp(subScore, "B+", 2) == 0) return 3.5;
	if (strncmp(subScore, "B0", 2) == 0) return 3.0;
	if (strncmp(subScore, "C+", 2) == 0) return 2.5;
	if (strncmp(subScore, "C0", 2) == 0) return 2.0;
	if (strncmp(subScore, "D+", 2) == 0) return 1.5;
	if (strncmp(subScore, "D0", 2) == 0) return 1.0;
	if (strncmp(subScore, "F", 1) == 0) return 0;
	return 0;
}

int main(void)
{
	char subj[50], personScore[3];
	float subScore, sum = 0, subSum = 0;

	for (int i = 0; i < SUBJECT_COUNT; i++)
	{
		scanf("%s %f %s", subj, &subScore, personScore);
		if (personScore[0] == 'P') continue;

		subSum += subScore;
		sum += subScore * personScore2score(personScore);
	}

	printf("%f", sum / subSum);

	return 0;
}