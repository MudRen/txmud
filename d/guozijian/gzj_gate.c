// Room: /d/guozijian/gzj_gate.c 

inherit ROOM;

void create() 
{ 
	set("short", "���Ӽ�");
	set("long", @LONG
�����ǹ��Ӽ�����ţ��ŵ��Ϸ������׽���д�ߡ������š���
�ֵ��Ա߿��о�����ͼ�����ŵ��ҷ�����ǽ������һ�麺����
������š����Ӽࡱ�������֣���˵�ǻʵ۵����ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yongdao1",
		"south" : "/d/changan/nhroad1",
]));
	set("objects", ([
		__DIR__"npc/soldier"	: 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *objs;
	int i,n;

	if ( (dir != "north" && dir != "n") || wizardp(me) )
		return ::valid_leave(me,dir);

	objs = deep_inventory(me);
	n = sizeof(objs);

	if(n)
	for(i=0;i<n;i++)
	{
		if( objs[i]->is_weapon())
		{
			message("vision", "ʿ���ȵ���������������Ӽ಻������У�\n", this_object());
			return notify_fail("ʿ����ס�����ȥ·��\n");
		}
	}

	
	return ::valid_leave(me,dir);
}
