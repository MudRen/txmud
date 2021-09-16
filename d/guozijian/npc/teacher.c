// teacher.c

inherit NPC;

void create()
{
	set_name("�׵���", ({ "teacher kong" }) );
	set("long", @LONG
һ�����׶г��۵����������˺ų��ǿ��ӵĺ����ѧ��Ԩ����
��ûʵ۵���ʶ��Ҳ����Դ�������õ�ʲô�̻塣
LONG
	);
	set("age", 52);
	set("attitude", "friendly");
	set("combat_exp", 10);
	set_skill("literate",100);
	set("chat_msg_combat", ({
		"�׵���е���������ԩ�޳ɱ��������\n",
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
		return notify_fail("��Ķ���ʶ�������Ѿ��ܸ��ˣ�Ҫ����ѧϰ������ֻ��ֱ���ҿ����ˡ�\n");
	gin_cost = 300 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill("literate",0);
	}

	if(me->query("potential") <= me->query("learned_points"))
		return notify_fail("�������˿׵���Ľ̻壬����������һ������\n");

	if( (int)me->query("gin") > gin_cost ) {
		printf("�������˿׵���Ľ̻壬�ƺ���Щ�ĵá�\n", );
		me->add("learned_points", 1);
		temp = random(me->query("int"))+ (int) me->query("learned_points")/800;
		me->improve_skill("literate",temp);
	} else {
		gin_cost = me->query("gin");
		write("�����̫���ˣ����ʲôҲû�����򵽡�\n");
	}

	me->receive_damage("gin", gin_cost ,"tire");
	me->start_busy(2);

	return 1;
}