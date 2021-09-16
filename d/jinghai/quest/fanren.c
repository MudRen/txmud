// fanren.c

mapping
xing = ([
"��":"li",
"��":"zhong",
"��":"ma",
"��":"zhao",
"��":"huo",
"���":"zhuge",
"Ǯ":"qian",
"����":"gongsun",
"��":"zhou",
"��":"mu",
"��":"deng",
"��":"bi",
"��":"liu",
]),

ming = ([
"����":"batian",
"����":"yiqiu",
"�ѵ�":"nandi",
"����":"youliang",
"����":"chuxiong",
"ǧ��":"qianshou",
"չ��":"zhanhai",
"�е�":"youde",
"����":"fuan",
"����":"chenglin",
"����":"guohai",
"��ʤ":"liansheng",
]),

pos = ([
"¹��" : ({"/d/lumaji/jing"}),
//"��ͬ��" : ({"/d/datong/luzhuxiang3"}),
"������" : ({"/d/path1/cc_tch16"}),
"��Ҵ�" : ({"/d/zuojiacun/e_kou"}),
]);

string npc = __DIR__"man";

mapping init_fanren(mapping quest,int exp)
{
	string name,id,file,*where;
	int a,b,c,d;
	object man,room;
	mapping q;

	if(!mapp(quest) || !sizeof(quest))
		return 0;

	where = keys(pos);
	a = random(sizeof(xing));
	b = random(sizeof(ming));
	c = random(sizeof(where));
	d = random(sizeof(pos[where[c]]));
	file = pos[where[c]][d];

	name = sprintf("%s%s",keys(xing)[a],keys(ming)[b]);
	id = sprintf("%s %s",values(xing)[a],values(ming)[b]);

	room = find_object(file);
	if(!room)
		room = load_object(file);
	if(!room)
		return 0;

	q = allocate_mapping(sizeof(quest)-1);
	q["quest"] = quest["quest"];
	q["begin_msg"] = sprintf(quest["begin_msg"],name);
	q["hint"] = sprintf(quest["hint"],where[c]);
	q["name"] = name;
	q["reward"] = quest["reward"];
	q["end_msg"] = quest["end_msg"];

	man = new(npc);
	man->set_name(name, ({ id }) );

	if(exp < 600000)	// 60 ��
	{
		man->set_skill("dodge",60);
		man->set_skill("parry",60);
		man->set_skill("blade",60);
		man->set_skill("longjiao-blade",40);
		man->set_skill("xian-steps",40);
	}

	else if(exp < 800000)
	{
		man->set_skill("dodge",90);
		man->set_skill("parry",90);
		man->set_skill("blade",90);
		man->set_skill("longjiao-blade",50);
		man->set_skill("xian-steps",50);
	}

	else if(exp < 1500000)
	{
		man->set_skill("dodge",120);
		man->set_skill("parry",120);
		man->set_skill("blade",120);
		man->set_skill("longjiao-blade",70);
		man->set_skill("xian-steps",70);
	}

	else if(exp < 2500000)
	{
		man->set_skill("dodge",160);
		man->set_skill("parry",160);
		man->set_skill("blade",160);
		man->set_skill("longjiao-blade",100);
		man->set_skill("xian-steps",100);
	}

	else
	{
		man->set_skill("dodge",200);
		man->set_skill("parry",200);
		man->set_skill("blade",200);
		man->set_skill("longjiao-blade",120);
		man->set_skill("xian-steps",120);
		man->set("max_kee",1500);
		man->set("max_gin",1500);
		man->set("max_sen",1500);
	}

	exp *= 75/100;
	if(man->query("combat_exp") < exp)
		man->set("combat_exp",exp);

	man->move(room);
	tell_object(room,name+"���˹�����\n");

	return q;
}
