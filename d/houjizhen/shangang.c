// shangang.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long", @LONG
���ǳ��������һ���س���˵�Ƿس�����ʵ��һ������ԣ���������һ��
�ƽ����˲��ٵ��ˣ���ʬ���������û����ȥ��ᣡ�������ǲŷ׷����⽨
��Щ�أ�����ȥ�������ǵ��԰�Ϣ����������ɱ��̫�أ����ﳣ�궼��������
��ģ������ĺ������洵�������Ե���ɭ�ɲ���ƽʱ��û�˸ҵ�������ֻ����
�ϵ���ѻ��ѽ��ѽ����ҵؽ��š�
LONG
	);
	set("exits", ([
	"northwest" : __DIR__"tomb",
	"east" : __DIR__"shulin3",
	]));
	setup();
//	replace_program(ROOM);
}

#include "heiyijob.h";

int init()
{
        add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
         object me;
         me = this_player();
         if( !arg || arg != "didao")
         return notify_fail("ʲô��\n");
         if ( arg =="didao")
        {
         write("���ߵ�һ�������Ӳݵķ�Ĺ���棬ͻȻ������һ���ص�����Ѹ�ٵ����˽�ȥ��\n");
         message("vision",
         me->name() + "���㲻ע�⣬ͻȻ��ʧ��һ����Ĺ����\n",
                     environment(me), ({me}) );
         me->move("/d/changan/duchang1");
         message("vision",
                  me->name() + "ͻȻ������һ�������Ӳݵķ�Ĺ���棬��������������˺ܾã�ֻ����û�з��֣�\n",
                             environment(me), ({me}) );
          }
          return 1;

}
