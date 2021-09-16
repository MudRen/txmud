// edoor  ����

inherit ROOM;

void create()
{
	set("short", "�����Ƕ���");
        set("long", @LONG
�����ǳ����ǵĶ��ţ���ר�����͹����ʹ��Ļ�����������
ÿ�춼��������ʳ���Ϲ��߲ˡ���������Ĵ󳵴�������뾩�ǡ�
�������Ź�æ�ż������ĳ��������ˡ��ڳ��ŵ�һ�ԣ�����һ
������(bugao)�������������ǳ����ǵĶ��������
LONG
        );

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([
		"east"	:	__DIR__"out_changan_e",
                "west"            : __DIR__"eroad4",
]) );
/*
	// gate settings
	// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["east" : __DIR__"out_changan_e"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
�����ǳ����ǵĶ��š�����������ʱ�䣬�����Ѿ������ˡ�
�����ĵ�ֻ���سǵ�ʿ���ǻ������վ�����
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","�����Ƕ���" );

	// end.
*/
	set("outdoors","changan");

	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));
	setup();
	replace_program(ROOM);
}

void init()
{
        add_action("do_huilu", "huilu");
}

int do_huilu(string arg)
{
	object me,ob;
	me = this_player();
	if( !arg || (arg!="guard" && arg!="guanbing") )
		return notify_fail("��Ҫ��¸˭��\n");

        if( me->query_temp("on_rided"))  // �ж��Ƿ���������
                return notify_fail("�س������������˵�����ٺ٣��������ǣ��������ʱ��������ɡ�\n");

	if( me->is_busy())
		return notify_fail("�����ں�æ��������ȥ��¸�ɣ�\n");

        if(ob = present("silver_money", me) ){              
		message_vision("$N�ó�һ�������ݸ��س���������ͷ����˵���������������Т�����ģ���ȥ�ȵ��ɡ�\n\n", me);
		message_vision("��ͷ���س������������㣬�������֣�˵��������ȥ�ɡ�������򿪳�����$N��ȥ��\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "out_changan_e");
		return 1;
               }
	if(ob = present("gold_money", me)){                  
               message_vision("$N���˰��죬�������ϰ�����ʣ�޼��ˣ�ֻ���ó�һ���ƽ�ݸ��س�������\n��ͷ����˵��������������Т�����ģ���ȥ�ȵ��ɡ���\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "out_changan_e");
		return 1;
               }

	return notify_fail("��������������ȴ�������ϴ���Ǯ�����ˡ�\n");   
}