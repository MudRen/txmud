// chucangshi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��һ���ű��ŵ�һ��ùζ����������������������ҫ�£��㿴����
�����ݵĻҳ����ɶѳɶѵ���Ʒ����������䷿�䡣��������Ϊʲô��
�����뿪ʱ������Щ��ƷҲ���ߡ�
LONG);

        set("exits", ([
              "west" : __DIR__"shilu3",
        ]));

        set("objects", ([
                __DIR__"obj/shengzi" : 1,
        ]));

        setup();
	replace_program(ROOM);
}
