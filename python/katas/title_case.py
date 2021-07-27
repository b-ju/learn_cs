def title_case(sentence, minors = None):
	sentence = sentence.split()
	sentence[0] = sentence[0].capitalize()
	title_cased = ""	
	for word in sentence:
		if str(minors).rfind(word) == -1:
			title_cased += word.capitalize() + " "
		else:
			title_cased += word + " "
	return title_cased.strip()



def main():
	print(title_case("hello this is a sentence" ,"this is a"))	
	print(title_case("the small brown fox"))
if __name__== '__main__':
	main()
