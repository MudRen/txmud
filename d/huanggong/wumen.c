// Room: /d/huanggong/wumen.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������Ѿ������˻ʹ���������������¥֮�£�ÿ���ʵ۾�
�д�䣬���ﶼҪ���ӹ�������һƬϲ����������գ��޴��ͭ
�Ӹ߸������ڳ���֮�ϣ������ʾ�˵��������ɣ����������ǽ�
�ǵ��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"daolu1",
  "north" : __DIR__"taihm",
]));
        set("no_clean_up", 0);
	set("outdoors", "huanggong");
       
        setup();
        replace_program(ROOM);
}
