// Room: /d/fengtian/out_fengtian_s.c

inherit ROOM;

void create()
{
	set("short", "���츮������");
	set("long", @LONG
�ߵ�����͵��˷����ˡ������Ƿ��츮�����ţ������پ���
�̲��Ź��������ˡ����Ͽ�ȥ��һ����ֱ����ʯ�ٵ���
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"s_gate",
        "south" : "/d/path1/ft_s18",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"s_gate"]) );
	set( "close_look",@LONG
�����Ƿ��츮�⡣������һ����ʯ�ٵ������ĵ���Զ�����죬
�򱱿��Ƿ�������ţ�������ɫ���������Ѿ������ˡ�
LONG
);
	set( "gate_name","���츮����" );
*/
	set("outdoors","fengtian");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "north") )
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
