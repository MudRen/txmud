// guard.c
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dir;
        object ob, *guards;
        mixed old_target;

        if( me->is_busy() )
                return notify_fail("你现在没有办法分心去做这类事！\n");

        old_target = me->query_temp("guarding");

        if( !arg || arg=="" ) {
                if( !old_target )
                        return notify_fail("指令格式：guard <生物>|<物品>|<方向>\n");
                if( objectp(old_target) )
                        if( living(old_target) )
                                write("你正在守护著" + old_target->name() + "。\n");
                        else
                                write("你正守在" + old_target->name() + "一旁，防止别人拿走。\n");
                else
                        write("你正守住 " + old_target + " 的方向，不准任何人离开。\n");
                return 1;
        }

        ob = present(arg, environment(me));

        if( ob ) {
                if( ob==me ) return notify_fail("守卫自己？不用说你也会做，对吧。\n");

// added by find.
                if( ob->is_character() )
                {
                        if(arrayp(guards = ob->query_temp("guarded"))
                        && sizeof(guards) >= 4 )
                        return notify_fail("已经有很多人在保护"+ob->name()+"了。\n");
                }
// end.

                me->set_temp("guarding", ob);
        }
        else if( environment(me)->query("exits/" + arg) ) {
                if( environment(me)->query(SAFE_ENV) )
                        return notify_fail("这里不准战斗——也不准堵住别人去路！\n");
		/* 这个实在没必要，使游戏少了些趣味。先去掉。added & removed by Find.*/
		//if( environment(me)->query("outdoors") && userp(me) )
		//	return notify_fail("你发现一个人很难守住这个方向。\n");
                me->set_temp("guarding", arg);
        }
        else if( arg!= "cancel" )
                return notify_fail("你要守卫谁，什么，或是哪个方向？\n");

        if( objectp(old_target) ) {
                guards = old_target->query_temp("guarded");
                // added by Find.
                if(arrayp(guards))
                // end.
                guards -= ({ me });
                old_target->set_temp("guarded", guards);
                if( living(old_target) )
                        tell_object( old_target, me->name() + "不再保护你了。\n");
        } else if( stringp(dir = me->query_temp("pending/guarding")) ) {
                guards = environment(me)->query("guarded/" + dir);
                if( arrayp(guards) ) {
                        guards -= ({ me });
                        environment(me)->set("guarded/" + dir, guards);
                }
                me->delete_temp("pending/guarding");
        }

        if( arg=="cancel" ) {
                write("Ok.\n");
                return 1;
        }

        if( objectp(ob) ) {
                ob->add_temp("guarded", ({ me }) );
                if( living(ob) )
                        message_vision("$N开始保护$n。\n", me, ob);
                else
                        message_vision("$N站到地上的$n一旁守著，以免别人取走。\n", me, ob);
        } else {
                me->set_temp("pending/guarding", arg);
                environment(me)->add("guarded/" + arg, ({ me }));
                message_vision("$N开始守住往 " + arg + " 的方向不让任何人通行。\n", me);
        }

	if(me->is_fighting())
		me->start_busy(1);
        return 1;
}

int help(object me)
{
        write(@TEXT
指令格式：guard [<某人>|<地上某物>|<某个出口>|cancel]

这个指令有三种作用方式，分别如後：

guard <某人>      保护<某人>，当他／她受到攻击时，保护者会自动加入战斗，并且
                  受攻击的顺位会排在被保护者前面，由於只有攻击顺位前四个目标
                  才会受到攻击，因此理论上如果有四个人  guard 你，你就不会受
                  到任何攻击。

guard <地上某物>  守住放在地上的某件东西，防止别人来拿，只要你还在这个房间，
                  而且没有忙著其他事，别人就无法拿走这件东西。当然，如果别
                  人本事比你大也没办法。

guard <某个出口>  守住某个出口防止所有人从这个出口离开，可以用来阻拦善於逃跑
                  的敌人或拦路打劫做坏事。但每次成功的挡住别人的去路都要耗费
		  一定的体力，如果是一条繁华的大路经常有人需要通过，守住这样
		  的路口也是有一定风险的。

guard cancel      取消先前的 guard 对象。
guard             不接任何参数会显示你目前 guard 的对象。

注意，通常除了 guard <某人> 的情形以外，只要你一移动，guard 的状态就会解除。
TEXT
        );
        return 1;
}