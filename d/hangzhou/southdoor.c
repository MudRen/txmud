// Room: /d/hangzhou/southdoor.c

inherit ROOM;

void create()
{
	set("short", "���ݸ�����");
	set("long", @LONG
������Ǻ��ݳǵ����š��ٸ�����������æ�ż����������
�ˡ��ڶ����ǽ������һ������(bugao)�����治Զ���Ǻ��ݳ�
�Ĺ�̩�֡�
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("outdoors", "hangzhou");

	set("exits", ([ /* sizeof() == 1 */
		"south"	: __DIR__"out_hangzhou_s",
		"north" : __DIR__"bigroad",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_hangzhou_s"]) );

	set( "close_look",@LONG
�����Ǻ��ݳǵ����š������Ѿ������ˡ�ֻ���سǹٱ��ǻ�
վ�������Ĵ�Ѱ����
LONG
);
	set( "gate_name","���ݳ�����" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,

]));

	setup();
	replace_program(ROOM);
}
