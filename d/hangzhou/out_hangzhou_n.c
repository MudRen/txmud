// Room: /d/hangzhou/out_hangzhou_n.c

inherit ROOM;

void create()
{
	set("short", "���ݳǱ�����");
	set("long", @LONG
������ͳ��˺��ݳǡ������Ǻ��ݳǵı��ż����پ����̲�
�Ź��������ˡ��ǵı�����һ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"ndoor",
	"north" : "/d/path3/k_h40",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"ndoor"]) );

	set( "close_look",@LONG
�����Ǻ��ݳ��⡣������һ��������·�������Ǻ��ݳǵı�
�ţ������Ѿ������ˡ�
LONG
);

	set( "gate_name","���ݳǱ���" );
*/
	set("outdoors","hangzhou");
	setup();
	replace_program(ROOM);
}
