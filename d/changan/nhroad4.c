// /d/changan/nhroad4  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ����ǵ������֣��ǳ����������ֵ�֮һ�����ߵ�
���̺��٣�ة�ฮ�������ﲻԶ�ˣ���������Ľ�������Ҳ�в�
�١�������·���ܵ�սս�����ģ���ʱ�������������㡣����·
���������Żʹ���ǽ�����졣
LONG
        );

       set("exits", ([
                "south"            : __DIR__"whroad1",
                "east"             : __DIR__"nhroad3",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
