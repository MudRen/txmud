// wuguan.c ��ݴ��� 

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "��ݴ���");
        set("long", @LONG
ʮ�����ɵĺ�����Ű볨�ţ������һ��������(bian)��
Ժ�ڲ�ʱ������ݵ�����ϰ��ʱ�Ĵ�����
LONG
        );
       set("exits", ([
                "east"     : __DIR__"shilu",
          ]) );
       set("item_desc",([
       "bian" : HIY"�봨���\n"NOR,
          ]));

       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
