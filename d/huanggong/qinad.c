// Room: /d/huanggong/qinad.c

inherit ROOM;

void create()
{
        set("short", "�հ���");
        set("long", @LONG
������ǻ���ƽʱ�������ֵĵط�����Ͼ��ʱ������һ����
�������������������죬��Ϊ���ﲻ��̫�о���֮�����ԣ�
����ѯ��һЩ���յ����⣬��Ҳ�ǵ�����Ͻ�������������ͼ
��������������ϻ���һλ�ûʵۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yuhy",
  "north" : __DIR__"shenwm",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

