// wroad3  ��̩·

inherit ROOM;

void create()
{
        set("short", "��̩·");
        set("long", @LONG
�����ǳ���������ֱ��ߣ��ǳ���������ĵض�֮һ����
�������̺��ܵ궼�ڸ�����ƽ������������������������ϣ���
��ҲҪ�ƻ�ͨ��ֱ����ҹ���ݡ���ʱ���гֵ������־���������
���������ػص�Ѳ�ߡ������Ľֵ����ϱ����������죬�����Ǿ�
����������ꡰ���ĸ󡱡�
LONG
        );

	set("exits", ([
		"east"		   : __DIR__"bookroom",
		"north"            : __DIR__"wroad2",
		"south"            : __DIR__"wroad4",
]) );
	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}