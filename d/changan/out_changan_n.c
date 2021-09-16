// Room: /d/changan/out_changan_n.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�ߵ�����ͳ��˾�ʦ�������ǳ����ǵı��ż����پ����̲�
�Ź��������ˡ�������ȥ��һ�����᳤���ͷ���Ļ��������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ndoor",
  "north" : __DIR__"ch-ft1",
  "west" : "/d/houjizhen/shulin1",
]));

// gate settings
// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["south" : __DIR__"ndoor"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
�����ǳ������⡣������һ��������·�����ĵ���Զ�����죬
���Ͽ��ǳ����ǵı��ţ�������ɫ���������Ѿ������ˡ�
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","�����Ǳ���" );

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
	&& (dir == "south") )
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

