// /d/hangzhou/ndoor.c  ����

inherit ROOM;
void create()
{
        set("short", "���ݳǱ���");
        set("long", @LONG
������Ǻ��ݳǵı��š��ٸ�����������æ�ż����������
�ˡ��ڶ����ǽ������һ������(bugao)��������Ǻ��ݳǵ���
���֡�
LONG
        );

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([
		"north"	:	__DIR__"out_hangzhou_n",
                "south"            : __DIR__"minan01",
]) );
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"out_hangzhou_n"]) );

	set( "close_look",@LONG
�����Ǻ��ݳǵı��š������Ѿ������ˡ�ֻ���سǹٱ��ǻ�
վ�������Ĵ�Ѱ����
LONG
);
	set( "gate_name","���ݳǱ���" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,

]));
	set("outdoors","hangzhou");
	setup();
	replace_program(ROOM);
}