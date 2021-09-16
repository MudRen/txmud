//	/adm/daemons/aliasd.c

mapping global_alias = ([
	"l":	"look",
	"n":	"go north",
	"e":	"go east",
	"w":	"go west",
	"s":	"go south",
	"nu":	"go northup",
	"eu":	"go eastup",
	"wu":	"go westup",
	"su":	"go southup",
	"nd":	"go northdown",
	"ed":	"go eastdown",
	"wd":	"go westdown",
	"sd":	"go southdown",
	"ne":	"go northeast",
	"se":	"go southeast",
	"nw":	"go northwest",
	"sw":	"go southwest",
	"u":	"go up",
	"d":	"go down",
	"i":	"inventory",

// added by find. ����һЩ����ļ�.

/*********  ��ר��  *****************/
	"zt":		"zhen talk",
	"zyq":		"zhen yq",
	"zin":		"zhen in",
	"zs":		"zhen san",
	"zck":		"zhen check",
/*********  End  **********************/

// added by dicky
/*********  ����ר��  *****************/
        "ts":           "team san",
        "tyq":          "team yq",
        "tin":          "team in",
        "tt":           "team talk",
/*********  End  **********************/
	"wen":		"ask",
	"mp":		"menpai",
	"mp*":		"menpai*",
	"mp#":		"menpai#",
        "bai":		"apprentice",
        "dazuo":	"exercise",
        "du":		"study",
        "fangqi":	"abandon",
        "jifa":		"enable",
        "lian":		"practice",
        "mingsi":	"meditate",
        "tou":		"steal",
        "zisha":	"suicide",
        "xiulian":	"respirate",
	"xiang":	"surrender",
	"shui":		"sleep",
	"kk":		"kill",
	"desc":		"describe",
	"sheng":	"upgrade",
	"shifa":	"conjure",
	"zhuang":	"wield",
	"xie":		"unwield",
	"chuan":	"wear",
        "eryu":         "whisper",
	"tuo":		"remove",
// end.

]);

string process_global_alias(string arg)
{
	string *word;

	if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) )
	{
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}

mapping query_global_alias()
{
	if(!previous_object() || geteuid(previous_object()) != ROOT_UID)
		return 0;

	return global_alias;
}
