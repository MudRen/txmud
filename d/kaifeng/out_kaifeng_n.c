// Room: /u/w/wangs/b/kai94.c

inherit ROOM;

void create()
{
	set("short", "���ⱱ����");
	set("long", @LONG
��ΰ�ı����ǿ���ǵ����ţ����Ա���������������������
������ر�׳�ۡ������Ĵ���ӳ�����ֱ����Զ����һ�Ӷӵ�ʿ
�����������¥���߹������ﲻ���̯��㣬�಻׼������㶺
���������Ե�ʮ�����ࡢ���ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"ndoor",
	"north" : "/d/path2/ch_k42",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["south" : __DIR__"ndoor"]) );
        set( "close_look",@LONG
��ΰ�ı����ǿ���ǵ����ţ����Ա���������������������
������ر�׳�ۡ�������ɫ���������Ѿ������ˡ�
LONG
);
        set( "gate_name","���ⱱ��" );
*/
        set("outdoors","kaifeng");
	setup();
}
