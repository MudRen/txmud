// Room: /d/fengtian/out_fengtian_n.c

inherit ROOM;

void create()
{
	set("short", "���츮������");
	set("long", @LONG
�������ǵı����⡣�����Ƿ��츮�ı��ţ������پ�����
���Ź��������ˡ�����ԶԶ��ȥ�ǹ�ͺͺ��Ⱥɽ�����������
��������ϡ�١�
LONG
	);
	set("exits", ([
  "south" : __DIR__"n_gate",
  "north" : "/d/northft/ftn1",
]));

	set("outdoors", "fengtian");
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
