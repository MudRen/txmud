// Room: /d/fengtian/n_gate.c

inherit ROOM;

void create()
{
	set("short", "���챱��");
	set("long", @LONG
��Ϊ�����������ĳ��Ÿߴ����ΰ������һֱ�ǿ�������
������������Ĺؿڣ������Ϸ����Źپ������Ǿ��죬����һ��
������������צ����ǽ��һ����������������ַ���ǣ�������
�����վ��ǳ���
LONG
	);

	set("exits", ([
	"south" : __DIR__"guanlu4",
	"north" : __DIR__"out_fengtian_n",
]));
        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
