//jiulou_boss.c ��֥��������Ƶ���ϰ塣

inherit F_DEALER;

void create()
{
    set_name("����", ({ "a lai","boss" }) );
    set("title","�ƹ�");
	set("gender", "����" );
	set("age", 45);
	set("long",
        "���������֥�ֵ���ϰ壬��˵�Ǹ����仧��������������ͷ�Եġ�\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("vendor_goods",([
	__DIR__"obj/yuxiang":3,
	__DIR__"obj/tuofeng":5,
	__DIR__"obj/yuchi":3,
	__DIR__"obj/yinyu":5,
	__DIR__"obj/shizi_tou":10,
	__DIR__"obj/taxue":5,
]));
	setup();
	add_money("silver",10);
    carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!is_day())	return;
	switch( random(2) ) {
		case 0:
			say( "�ƹ��Ц�����˵���������÷��ɣ��������롣\n");
			break;
		case 1:
			say( "�ƹ��Ц�����˵�����������������÷��������⡣\n");
			break;
	}
}
