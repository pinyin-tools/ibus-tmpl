/* vim:set et sts=4: */
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <ibus.h>

#define IBUS_TYPE_RUSTPINYIN_ENGINE	\
	(ibus_rustpinyin_engine_get_type ())

GType   ibus_rustpinyin_engine_get_type    (void);

typedef struct _IBusRustPinyinEngine IBusRustPinyinEngine;
typedef struct _IBusRustPinyinEngineClass IBusRustPinyinEngineClass;

struct _IBusRustPinyinEngine {
    IBusEngine parent;

    /* members */
    GString *preedit;
    //mirror of preedit, only used for display purpose
    //in the interface, with modification (space, '|' cursor etc.)
    GString *preedit_display;
    gint cursor_pos;

    IBusLookupTable *table;
};

struct _IBusRustPinyinEngineClass {
    IBusEngineClass parent;
};

/* functions prototype */

static void ibus_rustpinyin_engine_init(IBusRustPinyinEngine *engine);
void ibus_rustpinyin_engine_destroy(IBusRustPinyinEngine *engine);

void ibus_rustpinyin_engine_focus_in  (IBusEngine *engine);
void ibus_rustpinyin_engine_focus_out (IBusEngine *engine);
void ibus_rustpinyin_engine_reset     (IBusEngine *engine);
void ibus_rustpinyin_engine_enable    (IBusEngine *engine);
void ibus_rustpinyin_engine_disable   (IBusEngine *engine);
void ibus_engine_set_cursor_location(
    IBusEngine *engine,
    gint x,
    gint y,
    gint w,
    gint h
);
void ibus_rustpinyin_engine_set_capabilities(
    IBusEngine *engine,
    guint caps
);
void ibus_rustpinyin_engine_page_up     (IBusEngine  *engine);
void ibus_rustpinyin_engine_page_down   (IBusEngine  *engine);
void ibus_rustpinyin_engine_cursor_up   (IBusEngine  *engine);
void ibus_rustpinyin_engine_cursor_down (IBusEngine  *engine);
void ibus_rustpinyin_property_activate(
    IBusEngine* engine,
    const gchar* prop_name,
    gint prop_state
);
void ibus_rustpinyin_engine_property_show(
    IBusEngine* engine,
    const gchar* prop_name
);
void ibus_rustpinyin_engine_property_hide(
    IBusEngine* engine,
    const gchar* prop_name
);

void ibus_rustpinyin_engine_commit_string(
    IBusRustPinyinEngine* rustpinyin,
    const gchar* string
);
void ibus_rustpinyin_engine_update(IBusRustPinyinEngine *rustpinyin);

/**
 * take the raw string typed by the user and insert it in the
 * application "as it"
 */
gboolean ibus_rustpinyin_engine_commit_preedit(
    IBusRustPinyinEngine *rustpinyin
);

/**
 * take the current selected candidate and insert it in the application
 * if no candidate we insert the raw text
 */
gboolean ibus_rustpinyin_engine_commit_candidate(
    IBusRustPinyinEngine *rustpinyin
);



void ibus_rustpinyin_engine_update_lookup_table (
    IBusRustPinyinEngine* rustpinyin
);

#endif
