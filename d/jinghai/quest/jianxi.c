// jianxi.c

string *surname = ({
"ÕÅ","Íõ","Àî","ÕÔ","³Â","Ñî","Îâ","Áõ","»Æ","ÖÜ",
"Ðì","Öì","ÁÖ","Ëï","Âí","¸ß","ºú","Ö£","¹ù","Ïô",
"Ð»","ºÎ","Ðí","ËÎ","Éò","ÂÞ","º«","µË","Áº","Ò¶",
"·½","´Þ","³Ì","ÅË","²Ü","·ë","Íô","²Ì","Ô¬","Â¬","ÌÆ","Ç®","¶Å","Åí","Â½",
});

mapping
pos = ([
"Â¹Âí¼¯" : ({"/d/lumaji/lu3", "/d/lumaji/lu10", "/d/lumaji/lu14","/d/path1/lmj10"}),
"ÅÅÔÆÕ¯" : ({"/d/path1/py9", "/d/path1/py5", "/d/path1/py3"}),
"×ó¼Ò´å" : ({"/d/path1/zjz9", "/d/zuojiacun/lu4", "/d/zuojiacun/lu14"}),
]);

string npc = __DIR__"jian";

mapping init_jianxi(mapping quest,int exp)
{
	string name,file, *where;
	mapping q;
	object room,man;
	int a,b;

	if(!mapp(quest) || !sizeof(quest))
		return 0;

	name = sprintf("¼éÏ¸%s",surname[random(sizeof(surname))]);

	where = keys(pos);
	a = random(sizeof(where));
	b = random(sizeof(pos[where[a]]));
	file = pos[where[a]][b];

	room = find_object(file);
	if(!room)
		room = load_object(file);
	if(!room)
		return 0;

	q = allocate_mapping(sizeof(quest)-1);
	q["quest"] = quest["quest"];
	q["begin_msg"] = sprintf(quest["begin_msg"],name);
	q["hint"] = sprintf(quest["hint"],where[a]);
	q["name"] = name;
	q["reward"] = quest["reward"];
	q["end_msg"] = quest["end_msg"];

	man = new(npc);
	man->set("name",name);

	if(exp < 500000)
	{
		man->set("max_kee",500);
		man->set("eff_kee",500);
		man->set("kee",500);
		man->set_skill("dodge",90);
		man->set_skill("parry",90);
		man->set_skill("unarmed",100);
		man->set_skill("force",100);
		man->set_skill("blade",90);
	}
	else if(exp < 700000)
	{
		man->set("max_kee",700);
		man->set("eff_kee",700);
		man->set("kee",700);
		man->set_skill("dodge",100);
		man->set_skill("parry",100);
		man->set_skill("unarmed",150);
		man->set_skill("force",100);
		man->set_skill("blade",90);
	}
	else if(exp < 900000)
	{
		man->set("max_kee",900);
		man->set("eff_kee",900);
		man->set("kee",900);
		man->set_skill("dodge",120);
		man->set_skill("parry",120);
		man->set_skill("unarmed",150);
		man->set_skill("force",120);
		man->set_skill("blade",120);
	}

	exp = exp/2+1000;
	if(man->query("combat_exp") < exp)
		man->set("combat_exp",exp);

	man->move(room);
	tell_object(room,name+"×ßÁË¹ýÀ´¡£\n");

	return q;
}
