// Room: /d/changan/out_changan_w.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�ߵ�����ͳ��˾��ǡ������ǳ����ǵ����ţ������پ�����
���Ź��������ˡ�������ȥ��һ����ֱ�Ļ��������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"wdoor",
        "west" : "/d/path2/ch_t1",
]));

// gate settings
// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["east" : __DIR__"wdoor"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
�����ǳ������⡣������һ��������·�����ĵ���Զ�����죬
�򶫿��ǳ����ǵ����ţ�������ɫ���������Ѿ������ˡ�
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","����������" );

// end.
	set("outdoors","changan");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "east") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("ͻȻ�ӱ�������������ʿ˵�����Ҵ�%s���Ǻ��ˣ���Ĳ��ͷ�����\n",
				inv[0]->query("name")));
	}

	return ::valid_leave(ob,dir);
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
               me->move(__DIR__ "wdoor");
		return 1;
               }
	if(ob = present("gold_money", me)){                  
               message_vision("$N���˰��죬�������ϰ�����ʣ�޼��ˣ�ֻ���ó�һ���ƽ�ݸ��س�������\n��ͷ����˵��������������Т�����ģ���ȥ�ȵ��ɡ���\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "wdoor");
		return 1;
               }

	return notify_fail("��������������ȴ�������ϴ���Ǯ�����ˡ�\n");   
}