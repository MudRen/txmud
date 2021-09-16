// haunt.c
#include <ansi.h>
inherit F_CLEAN_UP;
int scribe(object me, object sheet)
{
        object newsheet;
        string err;
        if (me->query("class") != "taoist")
                return notify_fail("��û�����������ؾ�������ʹ�÷�����\n");
        if( sheet->name() != "�ҷ�ֽ" ) 
                return notify_fail("��ʦ��Ҫ�����ҷ�ֽ�ϣ�\n");
        if( (int)me->query("mana") < 75 ) 
                return notify_fail("��ķ��������ˣ�\n");
        sheet->set_amount((int)sheet->query_amount() - 1);
        me->save();
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ʦ��" NOR, 
                ({ "save-me sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -75);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʦ����\n" NOR, me);
        return 1;
}
int do_burn(object sheet)
{ 
        object obj, soldier, me;
        me = this_player();
        if( !me->is_fighting() )
                return notify_fail("û����Ҫɱ�㣡\n");
        message_vision("$N���о��񣬼�����ζ�������һ��" + sheet->name() +
                "����������\n", this_player());
        me->receive_damage("sen", 20);
        if( random(me->query("max_mana")) < 50 ) {
                message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
                return 1;
        }
        seteuid(getuid());
        if( random(10) < 5 )
                soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me);
        me->remove_all_killer();
        message_vision(HIB "\n$N����$n�ı��󺰵�������ɱ��\n" NOR, me, soldier );
        message_vision(HIB "\n$n��$N��ס�����е��˵Ĺ�����\n" NOR, me, soldier );
        return 1;
}
