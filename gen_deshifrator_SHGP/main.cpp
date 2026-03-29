#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <time.h>
int main() {
	std::ofstream results("Results.txt", std::ios::app);
	uint64_t AMOUNT_OF_POPULATION{ 800 };
	uint64_t AMOUNT_OF_SURVIVING_KEYS{ static_cast<uint64_t>(AMOUNT_OF_POPULATION * 0.1) };
	uint32_t AMOUNT_OF_MUTANTS{ static_cast<uint32_t>(AMOUNT_OF_POPULATION * 0.03) };
	setlocale(LC_ALL, "Russian_Russia.1251");
	//std::string text{ "опхмъб йнлюмднбюмэе мюд юплхълх, йсрсгнб бяонлмхк, н ймъге юмдпее х онякюк елс опхйюгюмхе опхашрэ б цкюбмсч йбюпрхпс.ймъгэ юмдпеи опхеуюк б жюпебн - гюилхые б рнр яюлши демэ х б рн яюлне бпелъ дмъ, йнцдю йсрсгнб декюк оепбши ялнрп бнияйюл.ймъгэ юмдпеи нярюмнбхкяъ б депебме с днлю ябъыеммхйю, с йнрнпнцн ярнък щйхоюф цкюбмнйнлюмдсчыецн, х яек мю кюбнвйе с бнпнр, нфхдюъ яберкеиьецн, йюй бяе мюгшбюкх реоепэ йсрсгнбю.мю онке гю депебмеи якшьмш ашкх рн гбсйх онкйнбни лсгшйх, рн пеб нцпнлмнцн йнкхвеярбю цнкнянб йпхвюбьху : спю! мнбнлс цкюбмнйнлюмдсчыелс.рср фе с бнпнр, ьюцюу б деяърх - рх нр ймъгъ юмдпеъ, онкэгсъяэ нрясрярбхел ймъгъ х опейпюямнч онцндни, ярнъкх дбю демыхйю, йспэеп х дбнпежйхи.вепмнбюрши, напня" };//БЯРЮБХРЭ ЬР ЙЮОЯНЛ https://ru.texthandler.com/text-tools/letter-case-converter/
	std::string text{ "опхмъб йнлюмднбюмэе мюд юплхълх, йсрсгнб бяонлмхк, н ймъге юмдпее х онякюк елс опхйюгюмхе опхашрэ б цкюбмсч йбюпрхпс.ймъгэ юмдпеи опхеуюк б жюпебн - гюилхые б рнр яюлши демэ х б рн яюлне бпелъ дмъ, йнцдю йсрсгнб декюк оепбши ялнрп бнияйюл.ймъгэ юмдпеи нярюмнбхкяъ б депебме с днлю ябъыеммхйю, с йнрнпнцн ярнък щйхоюф цкюбмнйнлюмдсчыецн, х яек мю кюбнвйе с бнпнр, нфхдюъ яберкеиьецн, йюй бяе мюгшбюкх реоепэ йсрсгнбю.мю онке гю депебмеи якшьмш ашкх рн гбсйх онкйнбни лсгшйх, рн пеб нцпнлмнцн йнкхвеярбю цнкнянб йпхвюбьху : спю!мнбнлс цкюбмнйнлюмдсчыелс.рср фе с бнпнр, ьюцюу б деяърх - рх нр ймъгъ юмдпеъ, онкэгсъяэ нрясрярбхел ймъгъ х опейпюямнч онцндни, ярнъкх дбю демыхйю, йспэеп х дбнпежйхи.вепмнбюрши, н" };
	PrepareText(text);//СДЮКЪЕР ОПНАЕКШ, ГЮОЪРШЕ Х РД
	size_t l{ text.length() };
	std::vector<std::string> allowed_bigrams{ ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", };
	//	std::string allowed_bigrams{/* "юэ еэ хэ иэ нэ сэ ээ шэ зэ щэ чэ ъэ юз ез хз из нз сз зз шз щз чз ъз" */};

	CreateAllowedBigrams(allowed_bigrams, text, l - 1);
	//ЙНКБН ХРРЕПЮЖХИ
	size_t length{ text.length() };
	size_t column_length{ length / ROW_LENGTH };
	char* columns[ROW_LENGTH]{};//ЯНГДЮМХЕ ЯРНКАЖНБ РЕЙЯРЮ
	for (size_t i{}; i < ROW_LENGTH; ++i) {
		columns[i] = new char [column_length] {};
	}
	DevideTextByRows(text, columns, column_length);//ГЮОНКМЕМХЕ ЯРНКАЖНБ
	size_t test_number{};
	size_t itteration_counter{};
	Key* population;
	population = new Key[AMOUNT_OF_POPULATION];
	while (test_number < 40) {
		time_t mytime = time(NULL);
		struct tm* now1 = localtime(&mytime);
		int start_time{ (now1->tm_hour * 3600) + (now1->tm_min * 60) + now1->tm_sec };
		++test_number;
		CreatePopulation(population, AMOUNT_OF_POPULATION);//ГЮДЮ╦Р МЮВЮКЭМСЧ ОНОСКЪЖХЧ
		/*Key kuy;
		int32_t kyu[ROW_LENGTH]{};
		for (size_t i{}; i < ROW_LENGTH; ++i) {
			kuy.substitution[i] = kyu[i] - 1;
		}
		CountBadBigramsByKey(columns, kuy, column_length, bad_bigrams);
		std::cout << kuy.counter << '\n';*/
		bool result{};
		while (!result) {
			++itteration_counter;
			if (itteration_counter % 500 == 0) {
				std::cout << itteration_counter << '\n';
			}
			for (size_t i{}; i < AMOUNT_OF_POPULATION; ++i) {
				CountBadBigramsByKey(columns, population[i], column_length, allowed_bigrams);
			}
			if (StopFunc(population, AMOUNT_OF_POPULATION)) {
				result = true;
			}
			if (!result) {
				//ХГЛЕМЕМХХЕ ОНОСКЪЖХХ
				SwapKeysByCounter(population, AMOUNT_OF_POPULATION);
				RecreatePopulation(population, AMOUNT_OF_POPULATION, AMOUNT_OF_SURVIVING_KEYS, AMOUNT_OF_MUTANTS);
			}
			else {
				//БШБНД ПЕГСКЭРЮРЮ РЕЯРЮ
				time_t mytime = time(NULL);
				struct tm* now2 = localtime(&mytime);
				int time{ (now2->tm_hour * 3600) + (now2->tm_min * 60) + now2->tm_sec };
				time -= start_time;
				int per1{};
				int per2{};
				while ((time - 3600) >= 0) {
					++per1;
					time -= 3600;
				}
				while ((time - 60) >= 0) {
					++per2;
					time -= 60;
				}
				std::cout << "Test number: " << test_number << ".\tItteration number: " << itteration_counter
					<<". Time of work: " << per1 << ':' << per2 << ':' << time << '\n';
				for (int32_t i{}; i < AMOUNT_OF_POPULATION; ++i) {
					if (population[i].counter == 0) {
						for (int32_t j{}; j < ROW_LENGTH; ++j) {
							std::cout << population[i].substitution[j] + 1 << ' ';
						}
						std::cout << '\t' << population[i].counter << '\n';
					}
				}
				std::cout << '\n';
				results << "Test number: " << test_number << ".\tItteration number: " << itteration_counter
					<< ". Time of work: " << per1 << ':' << per2 << ':' << time << '\n';
				for (int32_t i{}; i < AMOUNT_OF_POPULATION; ++i) {
					if (population[i].counter == 0) {
						for (int32_t j{}; j < ROW_LENGTH; ++j) {
							results << population[i].substitution[j] + 1 << ' ';
						}
						results << '\t' << population[i].counter << '\n';
					}
				}
				results << '\n';
				itteration_counter = 0;
			}
		}
		//ВХЯРЙЮ ОНОСКЪЖХХ
		//for (size_t i{}; i < AMOUNT_OF_POPULATION; ++i) {
		//	population[i].counter = 0;
		//}
	}
	results.close();
	delete[] population;
	for (size_t i{}; i < ROW_LENGTH; ++i) {
		delete[] columns[i];
	}
}