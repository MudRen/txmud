// Room: /d/huanggong/taihd.c

inherit ROOM;

void create()
{
        set("short", "̫�͵�");
        set("long", @LONG
��������˼�����ã����ǵ���ҵ�Ȩ�����ģ�ÿ���»�
�۵ǻ���Ҫ��������д�䣮���аڷ��Żʵ۵ı�������ǰ����
���ڷ���һ���ɺף������ż��飬��¯��Ʈ��������̴�㣬����
�Ŀ������������������ٹ٣��������Ž��£�Ӣ�����������
��ǰһ�ӽ�������ʱ�����Ż��ϵİ�ȫ����ɲ����㳤���ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihm",
  "north" : __DIR__"zhonghd",
]));
        set("no_clean_up", 0);
        set("to", "rset long
");

        setup();
        replace_program(ROOM);
}