// /d/changan/nroad4  �������

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
���ǳ����Ǳ���ֵ����У���������Ĵ�֣�������������
��һ����Ҳ����ר�ŵ���;������ţ�������ǰ������ʤ�ţ���
�������̹����Ľ�ʿ�������š���������������˺ܶ࣬�ò���
�֡��������򶫺������ǳ���������֣����ǳ����ǵı��ţ�
����һֱ�߾��Ǳ���·�ˡ�
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad5",
                "north"           : __DIR__"ndoor",
                "south"           : __DIR__"nroad9",
                "east"            : __DIR__"nroad3",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
