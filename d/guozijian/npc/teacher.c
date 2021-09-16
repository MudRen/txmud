// teacher.c

inherit NPC;

void create()
{
	set_name("孔丹清", ({ "teacher kong" }) );
	set("long", @LONG
一个身穿白缎长袍的先生，此人号称是孔子的后代，学术渊博，
深得皇帝的赏识，也许可以从他那里得到什么教诲。
LONG
	);
	set("age", 52);
	set("attitude", "friendly");
	set("combat_exp", 10);
	set_skill("literate",100);
	set("chat_msg_combat", ({
		"孔丹清叫道：你我无冤无愁，杀我做甚！\n",
	}) );
	setup();
	carry_object(__DIR__"obj/tigercloth")->wear();
	add_money("coin", 20);
}

void init()
{
	add_action("do_listen","listen");
}

int do_listen()
{
	object me;
	int my_skill,gin_cost,temp;
	me = this_player();
	if( me->is_busy() ) return notify_fail(BUSY_MESSAGE);

	my_skill = me->query_skill("literate", 1);
	if( my_skill >= 300 )
		return notify_fail("你的读书识字能力已经很高了，要想再学习，恐怕只有直接找孔子了。\n");
	gin_cost = 300 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill("literate",0);
	}

	if(me->query("potential") <= me->query("learned_points"))
		return notify_fail("你聆听了孔丹清的教诲，不过好像是一无所获。\n");

	if( (int)me->query("gin") > gin_cost ) {
		printf("你聆听了孔丹清的教诲，似乎有些心得。\n", );
		me->add("learned_points", 1);
		temp = random(me->query("int"))+ (int) me->query("learned_points")/800;
		me->improve_skill("literate",temp);
	} else {
		gin_cost = me->query("gin");
		write("你今天太累了，结果什么也没有领悟到。\n");
	}

	me->receive_damage("gin", gin_cost ,"tire");
	me->start_busy(2);

	return 1;
}