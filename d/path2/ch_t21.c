// Room: /d/path2/ch_t21.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǰ������ˣ�������һƬ���֣���������һ���ޱߵ�
������ԭ������һ��С·���Ѷ�ȥ��·����б�ż���һ�����ӡ�
LONG
	);
        set("item_desc",([
          "����":"
                  southwest    ��ˮ��\n",  
])); 
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t20",
  "southwest" : __DIR__"ch_t22",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
