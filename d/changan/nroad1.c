// /d/changan/nroad1  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵı���ֵ���棬������񲢲�̫���֣���
��һ����ɱ�ĸо�������ż���Ҵ��߹����������������ߣ�һ��
���ϰ��մ�����������ط�����������������������죬������
����·��������һ�ұ����̡�
LONG
        );

	set("exits", ([
		"north"		  : __DIR__"weapony",
                "west"            : __DIR__"nroad2",
                "east"            : __DIR__"eroad8",
]) );

	set("outdoors","changan");

        setup();
	replace_program(ROOM);
}
