// yao_fanzi.c

#define CA_DIR	"/d/changan/"

#include <ansi.h>
inherit NPC;

int ask_xuelian(object me);

void create()
{
        set_name("药材贩子", ({ "yao fanzi","fanzi" }) );
        set("gender", "男性" );
        set("age", 37);
        set("long", "这时一位鬼鬼祟祟的药材贩子。\n");

	set(NO_KILL, 1);

	set("inquiry",([
	"药材" : "我就是专门贩药材的。\n",
	"天山雪莲" : (: ask_xuelian :),
	"雪莲" : "雪莲可是有真有假，采摘的季节不一样价格也不同，里面的学问可大啦。\n",
]));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_xuelian(object me)
{
	mapping
xing = ([
"张":"zhang",
"王":"wang",
"李":"li",
"赵":"zhao",
"吴":"wu",
"刘":"liu",
"黄埔":"huangpu",
]),

ming = ([
"志强":"zhiqiang",
"富贵":"fugui",
"高升":"gaosheng",
"进财":"jincai",
"登科":"dengke",
"仕通":"shitong",
]),

position = ([
"北" : CA_DIR"nroad4",
"西" : CA_DIR"wroad4",
"南" : CA_DIR"sroad4",
]);

	string name,id,file;
	int a,b,p;
	object room,npc;

	if(me->query("quest/shaolin_quest/name") != "天山雪莲")
	{
		write(sprintf(CYN"%s翻了翻眼睛说道：这东西是好弄的？！能见到真见到真货都是福气。\n"NOR,name()));
		return 1;
	}

	if(me->query("quest/shaolin_quest/asked_xuelian")
	|| me->query("quest/shaolin_quest/have"))
	{
		write(sprintf(CYN"%s说道：不是告诉你了还不赶紧去追。\n"NOR,name()));
		return 1;
	}

	a = random(sizeof(xing));
	b = random(sizeof(ming));
	p = random(sizeof(position));

	name = sprintf("%s%s",keys(xing)[a],keys(ming)[b]);
	id = sprintf("%s %s",values(xing)[a],values(ming)[b]);
	file = values(position)[p];
	room = find_object(file);
	if(!room)
		room = load_object(file);
	if(!room)
		return 0;

	npc = new(__DIR__"yao_npc");
	npc->set_name(name, ({ id }) );

	npc->move(room);
	tell_object(room,name+"走了过来。\n");

	write(sprintf(CYN"%s说道：真巧了，我上个月刚弄到一枝，不过不巧刚刚被人买走。
\t那位老客好像叫%s，我看他买了之后朝%s门方向走了，
\t你要是能找到他去和他商量商量吧。
\t告诉你我是10两银子卖给他的。
\n"NOR,name(),name,keys(position)[p]));

	me->set("quest/shaolin_quest/asked_xuelian",id);

	me->add("quest/shaolin_quest/hint",sprintf("\n      %s\n",
			sprintf("买雪莲的那位老客好像叫%s，我看他买了之后朝%s门方向走了。",
			name,keys(position)[p])) );

	return 1;
}
