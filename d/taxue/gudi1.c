// gudi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ�ȵ�");
        set("long",@LONG
�������ͱ�����Ĺȵף���������ϡ�١����ܿ���ȥ�߲����ʣ���ʯ
��ᾡ�����΢���Ĺ��ߣ��㿴������ʯ�������ż��ٷ�����ͼ�Σ�ÿ����
��״������ͬ�����������������䡣ͼ�ξ�����ʯ���ϳ����˼�����(zi)
��Ҳ�������������ơ���ʯ�ڲ�Զ��һ�����أ���ǰ��һ��Ĺ��(mubei)��
LONG);

	set("outdoors","taxue");

        set("tiehe_count",1);
        set("sword_count", 1);
       
        set("item_desc", ([
        "zi": HIB"�н���ѩ���ҵ���Ե��������⣬˲Ϣ֮�䡣\n\n"NOR,
	"mubei" : HIR"
                        
                       ������
                       ��һ��
                       ������
                       ���䩦
                       ��ѧ��
                       ���ک�
                       ��ʦ��
                       ������
                       ���©�
                       ����
                     �����ܩ���
                   ��  ��֮��  ��
                 ��    ��Ĺ��    ��
               ��      ������      ��
          ��������������������������������\n\n"NOR
        ]));

	set("exits",([
                "east" : __DIR__"gudi",
	]));

        set("objects", ([
                __DIR__"npc/master1" : 1,
        ]));

	setup();
}

void init()
{
        add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
        object me = this_player();

        if (arg != "mubei")
                return notify_fail("��Ҫ��ʲô��\n");
        
        message_vision("$N�ڷ�ǰ�򵹣����������ذ����İݡ�\n", me);
//        me->set_temp("taxue/gudi_bai", 1);
        return 1;
}