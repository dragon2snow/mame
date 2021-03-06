// license:???
// copyright-holders:???
/*************************************************************************

    Capcom Baseball

*************************************************************************/

class cbasebal_state : public driver_device
{
public:
	cbasebal_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
		m_spriteram(*this, "spriteram"),
		m_maincpu(*this, "maincpu"),
		m_gfxdecode(*this, "gfxdecode"),
		m_palette(*this, "palette") { }

	/* memory pointers */
	required_shared_ptr<UINT8> m_spriteram;
//  UINT8 *    m_paletteram;    // currently this uses generic palette handling

	/* video-related */
	tilemap_t    *m_fg_tilemap;
	tilemap_t    *m_bg_tilemap;
	UINT8      *m_textram;
	UINT8      *m_scrollram;
	UINT8      m_scroll_x[2];
	UINT8      m_scroll_y[2];
	int        m_tilebank;
	int        m_spritebank;
	int        m_text_on;
	int        m_bg_on;
	int        m_obj_on;
	int        m_flipscreen;

	/* misc */
	UINT8      m_rambank;
	DECLARE_WRITE8_MEMBER(cbasebal_bankswitch_w);
	DECLARE_READ8_MEMBER(bankedram_r);
	DECLARE_WRITE8_MEMBER(bankedram_w);
	DECLARE_WRITE8_MEMBER(cbasebal_coinctrl_w);
	DECLARE_WRITE8_MEMBER(cbasebal_textram_w);
	DECLARE_READ8_MEMBER(cbasebal_textram_r);
	DECLARE_WRITE8_MEMBER(cbasebal_scrollram_w);
	DECLARE_READ8_MEMBER(cbasebal_scrollram_r);
	DECLARE_WRITE8_MEMBER(cbasebal_gfxctrl_w);
	DECLARE_WRITE8_MEMBER(cbasebal_scrollx_w);
	DECLARE_WRITE8_MEMBER(cbasebal_scrolly_w);
	DECLARE_DRIVER_INIT(cbasebal);
	TILE_GET_INFO_MEMBER(get_bg_tile_info);
	TILE_GET_INFO_MEMBER(get_fg_tile_info);
	virtual void machine_start();
	virtual void machine_reset();
	virtual void video_start();
	UINT32 screen_update_cbasebal(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	void draw_sprites( bitmap_ind16 &bitmap, const rectangle &cliprect );
	required_device<cpu_device> m_maincpu;
	required_device<gfxdecode_device> m_gfxdecode;
	required_device<palette_device> m_palette;
};
