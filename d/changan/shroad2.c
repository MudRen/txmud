// shroad2  �ϻ�·

inherit ROOM;

void create()
{
        set("short", "�ϻ�·");
        set("long", @LONG
�����ǳ����ǵ��ϻ�·���ǳ����������ֵ�֮һ���������
��һ����ˮ�ž��ǻʹ��ˣ����н��ʹ���������ˮ����������
���Ĺ�Ա���������ɵ��ղ�ȵȣ�����·��������������˽�
������ż��Ҳ�ܿ���һЩ̫������������������ϰ����ֱͨ��
���ǵ����š�
LONG
        );

	set("exits", ([
                "west"             : __DIR__"shroad1",
                "east"             : __DIR__"shroad3",
                "south"            : __DIR__"sroad9",
                "north"            : __DIR__"jingsq1",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
