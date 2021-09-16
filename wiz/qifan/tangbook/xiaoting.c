 // Room: /d/tangmen/xiaoting.c

inherit ROOM;

void create()
{
  set("short", "�鷿����");
  set("long", @LONG
�������鷿��������ǽ����һ����ܣ���ǰ��С����һ��С
��ͯ������䳭д��ʲô��
LONG
  );
  set("exits", ([ /* sizeof() == 1 */
  "out": __DIR__"shufang",
]));

  set("objects", ([
  __DIR__"npc/sn" : 1,
]));

  setup();
  replace_program(ROOM);
}

int valid_leave(object me,string dir)
{
        if(!me)
                return 0;

        if(dir == "out" || dir == "out")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_tangmen_book() :))))
                        return notify_fail("��ū���ĵض���˵����Щ����ó�ȥѽ!\n");
        }

        return ::valid_leave(me,dir);
}

